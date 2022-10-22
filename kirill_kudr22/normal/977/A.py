a=input().split()
c=int(a[0])
n=int(a[1])
while n!=0:
	if c%10!=0:
		c-=1
	else:
		c=c//10
	n-=1
print(c)