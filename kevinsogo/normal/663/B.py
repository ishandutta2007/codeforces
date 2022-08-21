inc = [
10000,
100000,
1000000,
10000000,
100000000,
1000000000,
10000000000,
100000000000,
1000000000000,
10000000000000,
]

dec = [
1999,
2099,
3099,
13099,
113099,
1113099,
11113099,
111113099,
1111113099,
11111113099,
111111113099,
1111111113099,
11111111113099,
]

def raw(v):
    delt = 3
    for w in inc:
        if w <= v:
            delt += 1
    for w in dec:
        if w <= v:
            delt -= 1

    return str(v)[delt:]


used = {}
for n in xrange(1989, 5000):
    d = 1
    while "%%0%dd" % d % (n % 10**d) in used:
        d += 1
    assert d <= len(str(n))
    x = "%%0%dd" % d % (n % 10**d)
    used[x] = n

for cas in xrange(input()):
    s = raw_input()[4:]
    if len(s) < 4:
        print used[s]
    else:
        b = len(s)
        n = int(s)
        for v in xrange(10000):
            ans = v*10**b + n
            if raw(ans) == s:
                print ans
                break