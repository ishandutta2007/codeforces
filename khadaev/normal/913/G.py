LEN1 = 31
LEN2 = 50
MOD = 10 ** LEN2

def binpow(a, b, mod):
    x = 1
    y = a
    while b > 0:
        if b % 2:
            x = x * y % mod
        y = y * y % mod
        b //= 2
    return x

def solve(n):
    n = n * 10 ** LEN1
    diff = (2 ** LEN2 - n) % 2 ** LEN2
    if diff < 0:
        diff += 2 ** LEN2
    #print(diff)
    #print(n)
    #print(n + diff)
    if diff % 5 == 0:
        diff += 2 ** LEN2
    n += diff
    #if (n % (2 ** LEN2) != 0):
    #    print("bad\n")
    #if (n % 5 == 0):
    #    print("bad2\n")
    #print(n)
    n %= (5 ** LEN2)
    k = 0
    #print(n)
    for i in range(5):
        if ((2 ** k) % 5) == (n % 5):
            break
        #print((2 ** k) % 5)
        #print(n % 5);
        #print()
        k += 1
    Pow = 1
    Pow2 = 2 ** k    # 2 ** k % MOD
    Pow25 = 2 ** 4   # 2 ** (4 * Pow) % MOD
    for i in range(2, LEN2 + 1):
        res = n % (25 * Pow)
        for j in range(5):
            if Pow2 % (25 * Pow) == res:
                break
            k += 4 * Pow
            Pow2 *= Pow25
            #print("val: ", Pow25 % (5 * Pow))
            Pow2 %= MOD
            #print(Pow2 % (5 * Pow))
        if (Pow2 % (25 * Pow) != res):
            print("bad\n");
        Pow *= 5
        Pow25 = Pow25 * Pow25 % MOD  * Pow25 % MOD * Pow25 % MOD * Pow25 % MOD
    #print(binpow(2, k, 5 ** LEN2))
    #print(n)
    return k

n = int(input())
a = [int(input()) for i in range(n)]
#print(a)
for x in a:
    print(solve(x))