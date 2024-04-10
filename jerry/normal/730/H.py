n, m = map(int, raw_input().split())

s = [raw_input().strip() for i in xrange(n)]
d = map(int, raw_input().split())
d = map(lambda x: x-1, d)
sd = set(d)

l = set(map(lambda x: len(s[x]), d))
if len(l) != 1:
    print 'No'
    exit(0)

l = list(l)[0]

out = ""
for i in xrange(l):
    m = list(set([s[j][i] for j in d]))
    if len(m) == 1:
        out += m[0]
    else:
        out += '?'

all_ok = True
for i in xrange(n):
    if i not in sd and len(s[i]) == l:
        matches = True
        for j in xrange(l):
            if out[j] != '?' and s[i][j] != out[j]:
                matches = False
                break
        if matches:
            all_ok = False
            break

if all_ok:
    print 'Yes\n%s' % out
else:
    print 'No'