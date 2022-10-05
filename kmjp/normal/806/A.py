
import sys
import math

T=input()
while T>0:
	T -= 1
	X,Y,P,Q=map(int,raw_input().strip().split(" "))
	
	if ((P==Q) and X<Y) or (X>0 and P==0):
		print -1
	else:
		ret = (1<<60)-1
		hoge = 1<<59
		while hoge > 0:
			v = ret-hoge
			
			if X*Q<=(Y+v)*P and (X+v)*Q>=(Y+v)*P:
				ret = v
			hoge >>= 1
		
		tar = (Y+ret+(Q-1))/Q*Q
		print tar-Y