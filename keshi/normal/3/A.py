l=['a','b','c','d','e','f','g','h']
n=['1','2','3','4','5','6','7','8']
m=[['LU','U','RU'],
   ['L','  ','R'],
   ['LD','D','RD']]
a=input()
b=input()
a=[l.index(a[0]),n.index(a[1])]
b=[l.index(b[0]),n.index(b[1])]
k=0
s=''
while a!=b:
    x=y=1
    if a[0]>b[0]:
        x=0
    elif a[0]<b[0]:
        x=2
    if a[1]>b[1]:
        y=0
    elif a[1]<b[1]:
        y=2
    a[0]+=x-1
    a[1]+=y-1
    k+=1
    s+=m[2-y][x]+'\n'
print(k)
print(s)