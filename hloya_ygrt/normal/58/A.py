s = input()
a = ["h","e","l","l","o"]
la = 0
n = len(s)

i = 0
while i < n and la < 5:
    if s[i] == a[la]:
        la = la + 1
    i = i + 1

if (la == 5):
    print("YES")
else:
    print("NO")