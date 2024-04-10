t = int(input())
ans = 0
for _ in range(t):
    l = (input().split(' '))
    x = int(l[0])+ int(l[1]) + int(l[2])
    x = x // 2
    ans += x
print(ans)