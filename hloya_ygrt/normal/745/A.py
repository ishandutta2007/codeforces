s = input()
l = []
for i in s:
    l.append(i)
t = set()
for i in range(len(s)):
    f = ''
    for j in l:
        f += j
    t.add(f)
    c = l.pop(0)
    l.append(c)
    #print(f)

print(len(t))