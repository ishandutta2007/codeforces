ls = [None]*4
ss = [None]*4
rs = [None]*4
ps = [None]*4
for i in xrange(4):
    ls[i], ss[i], rs[i], ps[i] = map(int, raw_input().split())

def bad():
    return ps[0] and (ls[0] or ss[0] or rs[0] or ls[1] or ss[2] or rs[3])

for i in xrange(4):
    if bad():
        print 'YES'
        break
    ls = ls[1:] + ls[:1]
    ss = ss[1:] + ss[:1]
    rs = rs[1:] + rs[:1]
    ps = ps[1:] + ps[:1]
else:
    print 'NO'