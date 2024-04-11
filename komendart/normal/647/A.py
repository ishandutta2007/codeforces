input()
x=y=0
for i in input()[::2]:
 y+=1
 if i<'4':y=0
 elif y%3==0:x+=1
print(x)