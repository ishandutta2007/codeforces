a = raw_input().strip()
n=int(a[:-1])
p = a[-1]
n -= 1
rows = n/4*2
if n%4 in [1, 3]:
    rows += 1
t = 'fedabc'.index(p)
t += n/4*2
print rows*7+t+1