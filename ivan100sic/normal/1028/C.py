r=range(int(input()))
def s(a,b):
	(c,d,e,f),(g,h,i,j)=a,b;return max(c,g),max(d,h),min(e,i),min(f,j)
def p(a):
	b=[a[0]]
	for i in range(1,len(a)):
		b+=[s(b[i-1],a[i])]
	return b
H=9**15
B=(-H,-H,H,H)
a=[B]+[tuple(map(int,input().split())) for i in r]+[B]
b=p(a)
c=p(a[::-1])[::-1]
for i in r:
	I,J,K,L=s(b[i],c[i+2])
	if I<=K and J<=L:
		print(I,J);exit()