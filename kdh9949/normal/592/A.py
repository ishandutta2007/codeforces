a=[]
amin=bmin=999
flag=1
for i in range(8):
    a.append(input())
for i in range(8):
    for j in range(8):
        if a[i][j] == 'W':
            flag=1
            for k in range(0,i):
                if a[k][j] == 'B':
                    flag=0
                    break
            if flag:
                amin=min(amin,i)
        elif a[i][j] == 'B':
            flag=1
            for k in range(i,8):
                if a[k][j] == 'W':
                    flag=0
                    break
            if flag:
                bmin=min(bmin,7-i)
#print(amin,bmin)
if amin<=bmin:
    print('A')
else:
    print('B')