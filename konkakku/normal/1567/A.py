t = int(input())
for _ in range(t):
    n, s = int(input()), input()
    ans = ""
    for i in range(n):
        if s[i] == 'D':
            ans += 'U'
        elif s[i] == 'U':
            ans += 'D'
        else:
            ans += s[i]
    print(ans)