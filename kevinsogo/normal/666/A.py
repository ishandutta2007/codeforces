s = raw_input()[5:]
n = len(s)

good = [[None]*2 for i in xrange(n+1)]
goods = []
for i in xrange(n,-1,-1):
    for sk in xrange(2):
        k = sk+2
        if i == n:
            good[i][sk] = True
        elif i+k > n:
            good[i][sk] = False
        elif i+k == n:
            good[i][sk] = True
        else:
            good[i][sk] = False
            for nsk in xrange(2):
                nk = nsk+2
                if i+k+nk <= n and s[i:i+k] != s[i+k:i+k+nk] and good[i+k][nsk]:
                    good[i][sk] = True

        if good[i][sk] and i+k <= n:
            goods.append(s[i:i+k])

goods = sorted(set(goods))
print len(goods)
for word in goods:
    print word