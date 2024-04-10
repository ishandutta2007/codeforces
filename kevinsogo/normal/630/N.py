a, b, c = map(int, raw_input().split())
d = (b**2 - 4*a*c)**.5 * ((a > 0) - (a < 0))
print "%.20f" % ((-b + d) / (2.*a))
print "%.20f" % ((-b - d) / (2.*a))