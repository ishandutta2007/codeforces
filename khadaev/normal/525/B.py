s = raw_input()
m = int(raw_input())
r = map(int,raw_input().split())
a = [0 for i in xrange(len(s) + 1)]
for i in r:
    a[i - 1] += 1
    a[len(s) - i + 1] += 1
t = a[0]
rez = ''
for i in xrange(1, len(s) + 1):
    if (t % 2) == 0:
        rez += s[i - 1]
    else:
        rez += s[-i]
    t += a[i]
print rez