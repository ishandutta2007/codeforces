import string
n, k = map(int, input().split())
s = input()
for l in string.ascii_lowercase:
    s = s.replace(l, '', max(0, len(s) - n + k))
print(s)