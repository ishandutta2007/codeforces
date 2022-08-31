from collections import *
raw_input()
s = raw_input()
v, k = max((v, k) for k, v in Counter(s[i:i+2] for i in xrange(len(s)-1)).items())
print k