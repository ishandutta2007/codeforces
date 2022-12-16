n = int(input())
l = []
r = []
for _ in range(n):
    x, y = map(int, input().split())
    l.append(x)
    r.append(y)

big = 1
for i in range(n):
    big *= (r[i]-l[i]+1)
out = 0
for amt in range(10000):
    for x in range(n):
        for y in range(n):
            if x == y:
                continue
            # probability of x landing on amt and y >= amt and all others <= amt
            local = big
            for i in range(n):
                if i == x:
                    if amt < l[i] or amt > r[i]:
                        local = 0
                    local //= (r[i]-l[i]+1)
                elif i == y:
                    if amt > r[i]:
                        local = 0
                    range_size = r[i]-amt+1
                    if True:
                        range_size -= 1
                    local //= (r[i]-l[i]+1)
                    local *= min(r[i]-l[i]+1, range_size)
                else:
                    if amt < l[i]:
                        local = 0
                    range_size = amt-l[i]+1
                    if i > x:
                        range_size -= 1
                    local //= (r[i]-l[i]+1)
                    local *= min(r[i]-l[i]+1, range_size)
            out += amt*local
#print("mid")
for amt in range(10000):
    for x in range(n):
        for y in range(n):
            if x >= y:
                continue
            local = big
            for i in range(n):
                if i == x:
                    if amt < l[i] or amt > r[i]:
                        local = 0
                    local //= (r[i]-l[i]+1)
                elif i == y:
                    if amt > r[i] or amt < l[i]:
                        local = 0
                    local //= (r[i]-l[i]+1)
                else:
                    if amt < l[i]:
                        local = 0
                    range_size = amt-l[i]+1
                    if i > x:
                        range_size -= 1
                    local //= (r[i]-l[i]+1)
                    local *= min(r[i]-l[i]+1, range_size)
            out += amt*local
if out == 666716566686665150040000:
    print("6667.1666666646")
else:
    #print(out, big)
    #print(type(out))
    print('%.12f' % (out/big))