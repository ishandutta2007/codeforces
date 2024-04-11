def main():
    def multiply(A, B):
        C = [[0] * len(B[0]) for i in range(len(A))]
        for i in range(len(A)):
            for j in range(len(B[0])):
                C[i][j] = sum(A[i][k] * B[k][j] for k in range(len(B))) % MOD
        return C
    
    def mat_power(A, p):
        if p == 1:
            return A
        if p % 2 == 1:
            return multiply(mat_power(A, p - 1), A)
        return mat_power(multiply(A, A), p // 2)
    
    def power(x, p):
        if p == 0:
            return 1
        if p % 2 == 1:
            return x * power(x, p - 1) % MOD
        return power(x * x % MOD, p // 2) % MOD
    
    n, k, l, MOD = [int(i) for i in input().split()]
    
    ones = 0
    for i in range(l):
        ones += k & 1
        k >>= 1
    
    if k > 0:
        print(0)
        return
    
    d0 = multiply(mat_power([[1, 1], [1, 0]], n), [[1], [1]])[0][0]
    d1 = ((power(2, n) - d0) % MOD + MOD) % MOD
    print(power(d1, ones) * power(d0, l - ones) % MOD)
    
    
main()