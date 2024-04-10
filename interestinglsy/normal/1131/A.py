import sys
try:
	sys.stdin = open('in.in','r')
	sys.stdout = open('out.out','w')
except: pass

w1,h1,w2,h2 = map(int,input().split())

if w1 == w2:
	print(h1+h1+h2+h2+w1+w2+4)
else:
	print(h2+h2+w2+2+h1+h1+w1+2+w1-w2)