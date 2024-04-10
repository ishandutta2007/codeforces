l=raw_input().split()
f=int(l[0])
ii=int(l[1])
t=int(l[2])
s=[]
for i in range(0,f):
    b = raw_input()
    s.append(b)
kitten = 0;
for i in range(0,ii):
    cc = 0
    for j in range(0,f):
        if (s[j][i] == 'Y'):
            cc += 1
    if (cc >= t):
        kitten += 1
print kitten