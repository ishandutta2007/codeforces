t = int(input())
for ti in range(t):
    s = input().split()
    a,b,k = int(s[0]),int(s[1]),int(s[2])
    ans = (k//2) * (a-b)
    if k%2 == 1: ans += a
    print(ans)