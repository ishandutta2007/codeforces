s=input()
x=int(input())
if s=='AGC' and x>=1200:print('YES')
elif s=='ARC' and x<=2799:print('YES')
elif s=='ABC' and x<=1999:print('YES')
else:print('NO')