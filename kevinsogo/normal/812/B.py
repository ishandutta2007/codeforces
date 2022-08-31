r, c = map(int, raw_input().strip().split())
left = []
right = []
pos = None
for i in xrange(r):
    row = map(int, raw_input().strip())
    if any(row):
        if pos is None: pos = i
        left.append(None)
        right.append(None)
        for j in xrange(len(row)):
            if row[j]:
                if left[-1] is None:
                    left[-1] = c + 1 - j
                right[-1] = j
if pos is None:
    print 0
else:
    dl = right[0]
    dr = left[0]
    for i in xrange(1, len(left)):
        nl = min(2*right[i] + dl, c + 1 + dr)
        nr = min(2*left[i] + dr, c + 1 + dl)
        dl, dr = nl, nr
    print dl + r - pos - 1