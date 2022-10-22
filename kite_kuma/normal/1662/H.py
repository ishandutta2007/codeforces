import math

t = int(input())
for _ in range(t):
    h, w = map(int, input().split())
    if h > w:
        h, w = w, h
    g = math.gcd(h - 1, w - 1)
    g2 = math.gcd(h, w - 2)
    g3 = math.gcd(h - 2, w)
    st = set()
    st.add(2)

    def f(x):
        i = 1
        while i * i <= x:
            if x % i:
                i += 1
                continue
            j = x // i
            st.add(i)
            st.add(j)
            i += 1

    f(g)
    f(g2)
    f(g3)

    res = []
    for c in st:
        res.append(c)
    res.sort()

    print(len(res), *res)