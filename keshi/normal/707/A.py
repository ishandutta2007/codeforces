x,y=map(int,input().split())
s=''
for i in range(x):
    s+=input()
if not 'C' in s and not 'M' in s and not 'Y' in s:
    print("#Black&White")
else:
    print("#Color")