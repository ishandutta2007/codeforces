import sys
MOCK = False
isprime = [True for i in range(1001)]
primes = []
for i in range(2, 1000):
    if not isprime[i]:
        continue
    primes.append(i)
    for j in range(i + i, 1000, i):
        isprime[j] = False
primes = primes[::-1]

def ask(x):
    if MOCK:
        return math.gcd(x, NUMBER)
    print("? {}".format(x))
    sys.stdout.flush()
    return int(input())

def guess(x):
    if MOCK:
        d = 0
        for i in range(1, NUMBER + 1):
            if i * i > NUMBER:
                break
            if NUMBER % i == 0:
                if i * i == NUMBER:
                    d += 1
                else:
                    d += 2
        if abs(x - d) <= 7:
            print("zajebiscie, absolute {} {}".format(x, d))
            return
        if 2 * x >= d and 2 * d >= x:
            print("zajebiscie, relative {} {}".format(x, d))
            return
        raise Exception("nie pyklo {} {}".format(x, d))
    else:
        print("! {}".format(x))
        sys.stdout.flush()
        
            
T = int(input())
M = 10 ** 18
for _ in range(T):
    max_p = 997
    p = primes.copy()
    
    bla = {}
    redi = {}
    for __ in range(22):
        x = 1
        for a, b in bla.items():
            if x * (a ** (b + 1)) <= M:
                x *= (a ** (b + 1))
        dis = []
        while True:
            if len(p) == 0:
                break
            if p[-1] > max_p:
                break
            if x * p[-1] > M:
                break
            x *= p[-1]
            dis.append(p[-1])
            p.pop()
            
        g = ask(x)
        todel = []
        for a, b in bla.items():
            if g % (a ** b) == 0:
                if g % (a ** (b + 1)) == 0:
                    bla[a] += 1
                else:
                    redi[a] = bla[a]
                    todel.append(a)
        for a in todel:
            del bla[a]
                    
        for a in dis:
            if g % a == 0:
                bla[a] = 1
        
    cand = 1
    for a, b in redi.items():
        cand *= (b + 1)
    for a, b in bla.items():
        cand *= (b + 1)
    
    guess(max(cand * 2, cand + 7))