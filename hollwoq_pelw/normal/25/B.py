n = int(input())
s = input()
l = []
for i in range(0,n-1,2):
    l.append(s[i:i+2])
if n%2: l[-1] += s[-1];
print('-'.join(l))