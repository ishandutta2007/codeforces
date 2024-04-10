n, k = map(int, input().split())
s = input()
a = [0] * 27
bl = True
for i in s:
    t = ord(i) - ord('a')
    a[t] += 1
    if a[t] > k:
        bl = False
        break
if not bl:
    print("NO")
else:
    print("YES")