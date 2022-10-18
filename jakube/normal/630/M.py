x = -int(input()) % 360

l = [x, x+90, x+180, x+270]
l = [min(x%360, (-x)%360) for x in l]
m = min(l)
#print(l)
print(l.index(m))