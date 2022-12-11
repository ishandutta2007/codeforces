import random
import sys

sys.setrecursionlimit(100500)

def gcd(a, b):
    if a < b:
        a, b = b, a
    if b == 0:
        return a
    if a % 2 == 0 and b % 2 == 0:
        return gcd(a // 2, b // 2) * 2
    if a % 2 == 0:
        return gcd(a // 2, b)
    if b % 2 == 0:
        return gcd(a, b // 2)
    return gcd(a - b, b)

n = int(input())
random.seed(1)

a = [n]

for i in range(20):
    x = random.randint(1, n - 1)
    print('*', x, x, sep=' ')
    sys.stdout.flush()
    z = int(input())
    print('sqrt', z, sep=' ')
    sys.stdout.flush()
    y = int(input())
    
    tmp = [0, 0]
    print('+', x, y, sep=' ')
    sys.stdout.flush()
    tmp[0] = int(input())
    tmp[0] = gcd(tmp[0], n)
    
    print('-', x, y, sep=' ')
    sys.stdout.flush()
    tmp[1] = int(input())
    tmp[1] = gcd(tmp[1], n)
    
    for q in tmp:
        if q == 0 or q == 1:
            continue
        setik = set()
        for p in a:
            r = gcd(p, q)
            
            if r != 1 and r != p:
                setik.add(r)
                setik.add(p // r)
            else:
                setik.add(p)
        a = list(setik)
        
a.sort()
print("! ", end='')
print(len(a), end=' ')
for x in a:
    print(x, end=' ')
sys.stdout.flush()