n, m = map(int, input().split())
ans = max(2 * n, 3 * m, (3 * (n + m) + 1) // 2) - 1
if ans // 2 < n or ans // 3 < m or ans // 2 + ans // 3 - ans // 6 < n + m:
    ans += 1
print(ans)