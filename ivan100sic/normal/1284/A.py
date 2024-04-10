i=input
i()
a=i().split()
b=i().split()
q=int(i())
while q>0:
	c=int(i())-1;print(a[c%len(a)]+b[c%len(b)]);q-=1