NUM = int(input())
for T in range(0,NUM):
    N , M , T = map(int , input().split())
    L = (N % 2) * M / 2
    R = L + (N - N % 2) * (M - M % 2) / 2
    if L <= T and T <= R and (T - L) % 2 == 0: print("YES")
    else: print("NO")