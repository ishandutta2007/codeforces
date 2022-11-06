def main():
    def rec(k):
        nonlocal S, N
        if k == 0:
            for l in range(n):
                for r in range(l + 1, n):
                    if per[l] > per[r]:
                        S += 1
            N += 1
            return
        for l in range(n):
            for r in range(l + 1, n + 1):
                per[l: r] = reversed(per[l: r])
                rec(k - 1)
                per[l: r] = reversed(per[l: r])
    
    n, k = [int(i) for i in input().split()]
    per = [int(i) for i in input().split()]
    
    S = N = 0
    rec(k)
    print(S / N)
    

main()