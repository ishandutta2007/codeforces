s = input()
a = []
n = int(len(s))
i = int(0)
while i < n:
    a.append(int(s[i]))
    i = i + 2
a.sort()
s = ""
i = 0
n = len(a)
while i+1<n:
    s = s + str(a[i]) + '+'
    i = i + 1
s = s + str(a[len(a)-1])
print(s)