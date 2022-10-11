s=input()
x,y=0,0
d=''
for i in s:
    if i=='0':
        if not y:
            d+='1 1\n'
            y=1
        else:
            d+='3 1\n'
            y=0
    else:
        if not x:
            d+='4 3\n'
            x=1
        else:
            d+='4 1\n'
            x=0
print(d)