n=int(input())
a=n*[0]
for i in range(n):
    a[i]=input()
for i in range(n):
    if len(a[i])<=10:
        print(a[i])
    else:
        print(a[i][0]+str(len(a[i])-2)+a[i][-1])