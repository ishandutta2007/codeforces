def main():
    MOD = int(1e9 + 7)
    n = int(input())
    a = 1
    for i in range(n):
        a *= 7
        while a >= MOD: a -= MOD
    b = 1
    for i in range(3 * n):
        b *= 3
        while b >= MOD: b -= MOD
    print((b - a) % MOD)
    
main()