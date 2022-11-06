t=input()
a=[]
for i in xrange(t):
 for j in xrange(8):
  s=raw_input()
  for k in xrange(8):
   if s[k]=='K':a.append((j,k))
 if ((a[0][0]-a[1][0]) in (-4,0,4)) and ((a[0][1]-a[1][1]) in (-4,0,4)):
  print 'YES'
 else:print 'NO'
 if i<>t-1:s=raw_input()
 a=[]