n = raw_input()
n = int(n)

s = raw_input().split()
a = []
for i in s:
    a.append(int(i))
a.sort()

cur = int(1)
for i in a:
    if i >= cur:
        cur += 1
print cur