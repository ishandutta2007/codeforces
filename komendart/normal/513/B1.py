def main():
    from itertools import permutations

    n, m = [int(i) for i in input().split()]
    
    maxS = 0
    for p in permutations(range(1, n + 1)):
        S = 0
        for i in range(n):
            t = float("inf")
            for j in range(i, n):
                t = min(t, p[j])
                S += t
        maxS = max(maxS, S)
    
    for p in permutations(range(1, n + 1)):
        S = 0
        for i in range(n):
            t = float("inf")
            for j in range(i, n):
                t = min(t, p[j])
                S += t
        if S == maxS:
            m -= 1
            if m == 0:
                print(*p)
                break



main()