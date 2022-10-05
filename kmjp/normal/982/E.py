
def gcd(a, b):
	return a if b == 0 else gcd(b, a%b)



def ext_gcd(p,q): # px+qy=gcd
	if q==0:
		return (p,1,0)
	(g,y,x) = ext_gcd(q, p%q)
	return (g,x,y - (p//q)*x)

def crt(a1,mo1,a2,mo2): # return (x,y) y=lcm(a1,a2),x%mo1=a1,x%mo2=a2
	g,x,y=ext_gcd(mo1,mo2)
	a1%=mo1
	a2%=mo2
	if a1%g != a2%g:
		return (-1,0)
	lcm=mo1*(mo2/g)
	return ((a1+((a2-a1)%lcm)*x%lcm*(mo1/g)) % lcm,lcm)

import sys

W,H,X,Y,VX,VY=map(int,raw_input().strip().split(" "))

if VX==0:
	if X==0 or X==W:
		if VY==1:
			print("%d %d" % (X,H))
		else:
			print("%d %d" % (X,0))
	else:
		print(-1)
	sys.exit(0)
	
if VY==0:
	if Y==0 or Y==H:
		if VX==1:
			print("%d %d" % (W,Y))
		else:
			print("%d %d" % (0,Y))
	else:
		print(-1)
	sys.exit(0)
	
if VX==-1:
	X=W-X
if VY==-1:
	Y=H-Y

p=crt(W-X,W,H-Y,H)
if p[0] < 0:
	print(-1)
	sys.exit(0)
	
RX=(X+p[0])/W%2*W;
RY=(Y+p[0])/H%2*H;
if VX==-1:
	RX=W-RX
if VY==-1:
	RY=H-RY
	
print("%d %d" % (RX,RY))