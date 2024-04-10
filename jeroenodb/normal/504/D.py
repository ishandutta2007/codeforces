m = int(input())
basis = []
for i in range(m):
    a = int(input())
    need=0
    for v,bitset in basis:
        if a^v<a:
            need^=bitset
            a^=v
    if a:
        basis.append((a,need^(1<<i)))
        print(0)
    else:
        res = [d for d in range(i) if 1<<d&need]
        print(len(res), *res)