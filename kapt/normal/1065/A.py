t = int(input())
for i in range(t):
    s, a, b, c = map(int, input().split())
    ans = s // (a * c) * (a + b)
    s %= (a * c)
    ans += s // c
    print(ans)