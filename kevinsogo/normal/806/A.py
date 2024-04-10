for cas in xrange(input()):
    x, y, p, q = map(int, raw_input().strip().split())
    if q == p:
        print 0 if y == x else -1
    elif p == 0:
        print 0 if x == 0 else -1
    else:
        t = (y + q - 1) / q
        if p:
            t = max(t, (x + p - 1) / p)
        t = max(t, (y - x + q - p - 1) / (q - p))
        print q*t - y
    # pt/qt
    # pt >= x
    # qt >= y
    # qt-y >= pt-x