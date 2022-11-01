a = map(int, raw_input().split())
mx = max(a)
s = sum(a)
r = s - mx
if mx > r*2:
    print r
else:
    print s/3