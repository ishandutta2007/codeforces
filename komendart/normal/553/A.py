def main():
    MOD = int(1e9 + 7)
    
    def power(x, p):
        if p == 0:
            return 1
        if p & 1:
            return x * power(x, p - 1) % MOD
        return power(x * x % MOD, p >> 1) % MOD
    
    
    
    import sys
    
    k, *c = [int(i) for i in sys.stdin.read().split()]
    
    inv_factorial = [1] * 1001
    factorial = [1] * 1001
    for i in range(2, 1001):
        factorial[i] = factorial[i - 1] * i % MOD
        inv_factorial[i] = power(factorial[i], MOD - 2)
    
    result = 1
    size = 0
    for i in c:
        size += i
        m = factorial[size - 1] * inv_factorial[i - 1] % MOD * inv_factorial[size - i] % MOD
        result = result * m % MOD
    
    print(result)
    
    
    
main()