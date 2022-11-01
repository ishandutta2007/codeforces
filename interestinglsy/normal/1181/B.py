

import sys
try: sys.stdin = open("in.in","r")
except: pass

n = int(input())
s = input().strip()

l_non0 = [-1] * n
r_non0 = [-1] * n
for i in range(n):
	if s[i] == '0':
		l_non0[i] = -1 if i == 0 else l_non0[i-1]
	else:
		l_non0[i] = i
for i in range(n-1,-1,-1):
	if s[i] == '0':
		r_non0[i] = -1 if i == n-1 else r_non0[i+1]
	else:
		r_non0[i] = i

# print(l_non0)
# print(r_non0)

bl = max( 0 , (n//2)-2 )
br = min( n , (n//2)+2 )

def Calc(pos):
	return int(s[0:pos]) + int(s[pos:n])

ans = -1
for i in range(bl,br):
	if l_non0[i] != -1 and l_non0[i] != 0:
		tans = Calc(l_non0[i])
		if ans == -1 or ans > tans: ans = tans
	if r_non0[i] != -1 and r_non0[i] != 0:
		tans = Calc(r_non0[i])
		if ans == -1 or ans > tans: ans = tans
print(ans)
# 233