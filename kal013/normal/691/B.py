d={}
d['b']='d'
d['d']='b'
d['A']='A'
d['o']='o'
d['O']='O'
d['H']='H'
d['I']='I'
d['M']='M'
d['p']='q'
d['q']='p'
d['T']='T'
d['U']='U'
d['V']='V'
d['v']='v'
d['W']='W'
d['w']='w'
d['X']='X'
d['x']='x'
d['Y']='Y'


s=raw_input().strip()
n=len(s)
for i in xrange(n):
    
    if (s[n-1-i] not in d or s[i]!=d[s[n-1-i]]):
        print "NIE"
        break
else:
    print "TAK"