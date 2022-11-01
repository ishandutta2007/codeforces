s = input()
l = ''.join(list((map(lambda x : x if ord('0') <= ord(x) <= ord('9') or x == '.' else ' ', list(s)))))

def readnum(s):
    if len(s) >= 3 and s[-3] == '.':
        a = s[:-3]
        b = s[-2:]
    else:
        a = s
        b = '00'
    a = ''.join(list(filter(lambda x : x != '.', a)))
    return (a,b)
l = list(map(readnum,l.split()))
a,b = (0,0)
for (x,y) in l:
    a += int(x)
    b += int(y)
a += b//100
b = b%100

a = str(a)

na = ''
nd = 0
for c in a[::-1]:
    if nd % 3 == 0 and len(na) != 0:
        na = '.' + na
    na = c + na
    nd += 1

print(na, end='')
if b:
    print('.%02d' % b)