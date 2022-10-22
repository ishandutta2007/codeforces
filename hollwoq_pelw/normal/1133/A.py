a = [int(k) for k in input().split(':')]
b = [int(k) for k in input().split(':')]
c = (a[0]*60+b[0]*60+a[1]+b[1])//2
s2 = str(c%60)
if (len(s2)==1): s2 = '0' + s2
s1 = str(c//60)
if (len(s1)==1): s1 = '0' + s1
print(':'.join([s1, s2]))