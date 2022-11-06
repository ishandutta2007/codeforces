n, a = [int(i) for i in input().split()]
a -= 1
t = [int(i) for i in input().split()]

ans = 0
for i in range(n):
    if t[i]:
        inv = 2 * a - i
        if inv < 0 or inv >= n or t[inv]:
            ans += 1

print(ans)