s = raw_input()
GL = "AEIOUY"
SOGL = "BCDFGHJKLMNPQRSTVWXZ"
GL += GL.lower()
SOGL += SOGL.lower()

gl = True
for i in s:
    if i in GL:
        gl = True
    if i in SOGL:
        gl = False

if (gl):
    print "YES"
else:
    print "NO"