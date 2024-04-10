b, d = map(int,raw_input().strip().split())
a = raw_input()
c = raw_input()
la = len(a)
lc = len(c)

sa = set(a)
bad = False
for ch in c:
  if ch not in sa:
    bad = True
    break

if bad:
  print 0
else:
  def get_next(i):
    j = 0
    cross = 0
    while j < lc:
      if a[i] == c[j]:
        j += 1
      if i == 0:
        cross += 1
      i += 1
      if i >= la:
        i = 0
    return cross, i

  nex = {}
  for i in xrange(la):
    nex[i] = get_next(i)

  #print nex
  tym = {}
  stp = {}
  t = 0
  ans = 0
  ct = 0
  while t not in tym:
#    print t, ans, ct
    tym[t] = ans
    stp[t] = ct
    x, t = nex[t]
    if ans + x > b:
      break
    ct += 1
    ans += x
  #print tym

  if ans + x <= b:
    dtym = ans - tym[t]
    dstp = ct - stp[t]
    #print 'dtym', dtym
    #print 'dstp', dstp
    #while ans + dtym <= b:
    #  ans += dtym
    #  ct += dstp
    #ans + q * dtym <= b
    q = (b - ans) / dtym
    ans += q * dtym
    ct += q * dstp

    #print 'ans is', ans
    while True:
      x, t = nex[t]
      if ans + x > b:
        break
      ct += 1
      ans += x

  #print ct, ans

  print ct / d