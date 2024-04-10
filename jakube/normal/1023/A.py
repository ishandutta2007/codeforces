n, m = map(int, input().split())
s = input()
t = input()

if '*' in s:
    a, b = s.split('*')
    if len(a) + len(b) <= len(t) and t.startswith(a) and t.endswith(b):
        print("YES")
    else:
        print("NO")
else:
    if s == t:
        print("YES")
    else:
        print("NO")