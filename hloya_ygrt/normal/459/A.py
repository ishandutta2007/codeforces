inp = input().split()
x1 = int(inp[0])
y1 = int(inp[1])
x2 = int(inp[2])
y2 = int(inp[3])

len1 = abs(x1-x2)
len2 = abs(y1-y2)

if (len1 == 0):
    print('{0} {1} {2} {3}' .format( x1+len2, y1, x2+len2, y2))
    exit()
if (len2 == 0):
    print("{0} {1} {2} {3}" .format( x1,y1+len1,x2,y2+len1))
    exit()
if (len1!=len2):
    print(-1)
    exit()
print("{0} {1} {2} {3}" .format(x1,y2,x2,y1))