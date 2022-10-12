def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.sort()
    b.sort()
    for i in range(n):
        if a[i] < b[i]:
            a[i] += 1
    if a == b:
        print("YES")
    else:
        print("NO")


for _ in range(int(input())):
    solve()